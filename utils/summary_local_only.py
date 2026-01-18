#!/usr/bin/env python3
"""
Filters SUMMARY.md to show only local file entries, stripping external URLs.
Reduces token count for AI parsing by removing long .edu, YouTube, and other external links.

Usage:
    python utils/summary_local_only.py                    # Full file, local entries only
    python utils/summary_local_only.py "## Leisure"       # Specific section only
    python utils/summary_local_only.py --list-sections    # Show section headers and line counts
"""

import sys
import re
from pathlib import Path

SUMMARY_PATH = Path(__file__).parent.parent / "SUMMARY.md"


def is_external_url(line: str) -> bool:
    """Check if a line contains an external URL (http/https)."""
    return bool(re.search(r'\]\(https?://', line))


def get_sections(content: str) -> dict[str, tuple[int, int]]:
    """Return dict of section_name -> (start_line, end_line)."""
    sections = {}
    lines = content.splitlines()
    current_section = "Top"
    current_start = 0

    for i, line in enumerate(lines):
        if line.startswith("## "):
            # Close previous section
            sections[current_section] = (current_start, i - 1)
            # Start new section
            current_section = line[3:].strip()
            current_start = i

    # Close final section
    sections[current_section] = (current_start, len(lines) - 1)
    return sections


def filter_local_only(content: str, section: str = None) -> str:
    """Filter content to local entries only, optionally within a section."""
    lines = content.splitlines()

    if section:
        sections = get_sections(content)
        if section.startswith("## "):
            section = section[3:]
        if section not in sections:
            # Try case-insensitive match
            for s in sections:
                if s.lower() == section.lower():
                    section = s
                    break
            else:
                return f"Section '{section}' not found. Available: {', '.join(sections.keys())}"

        start, end = sections[section]
        lines = lines[start:end + 1]

    filtered = []
    for line in lines:
        if not is_external_url(line):
            filtered.append(line)

    return "\n".join(filtered)


def list_sections(content: str) -> str:
    """List all sections with line counts."""
    sections = get_sections(content)
    output = ["Sections in SUMMARY.md:", ""]
    for name, (start, end) in sections.items():
        line_count = end - start + 1
        output.append(f"  {name}: lines {start + 1}-{end + 1} ({line_count} lines)")
    return "\n".join(output)


def main():
    content = SUMMARY_PATH.read_text()

    if len(sys.argv) == 1:
        # No args: full file, local only
        print(filter_local_only(content))
    elif sys.argv[1] == "--list-sections":
        print(list_sections(content))
    else:
        # Section specified
        section = sys.argv[1]
        print(filter_local_only(content, section))


if __name__ == "__main__":
    main()
