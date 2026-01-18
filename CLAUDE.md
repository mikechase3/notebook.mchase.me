# Project: notebook.mchase.me

A GitBook-based markdown notebook containing notes from college and beyond.

## Critical Rules

### New Markdown Files Must Be Added to SUMMARY.md
When creating any new `.md` file that serves as documentation/content, it MUST be added to `SUMMARY.md` in the appropriate section.

## Working with SUMMARY.md

**WARNING**: SUMMARY.md is large (~1100+ lines) and line numbers shift frequently as content is added/removed. Never hardcode line numbers - always search for section headers dynamically.

### Main Sections
The file is organized into these top-level sections (marked by `## SectionName`):
- **Inbox** (top of file, before Career)
- **Career** - Professional, technical, computer science topics (~920 lines, largest section)
- **Leisure** - Hobbies, games, entertainment
- **Maintenance** - System maintenance, life admin
- **Relations** - Relationships and social topics

### Utilities for SUMMARY.md

**Preferred: Use the local-only filter** to reduce tokens by stripping external URLs:
```bash
# List sections with current line ranges
python3 utils/summary_local_only.py --list-sections

# Get a section with URLs stripped (much smaller output)
python3 utils/summary_local_only.py "## Leisure"

# Full file, local entries only
python3 utils/summary_local_only.py
```

**Alternative: Direct grep for targeted edits:**
```bash
# Find section start
grep -n "^## Leisure" SUMMARY.md

# Find specific entry
grep -n "Computer Setup" SUMMARY.md
```

Then read a window around the match using Read with offset/limit.

### GitBook Entry Format
```markdown
* [Title](path/to/file.md)
  * [Nested Item](path/to/nested.md)
    * [Deeper Nested](path/to/deeper.md)
```
- Use 2 spaces per nesting level
- External links: `* [Link Text](https://example.com)`

### Adding a New Entry
1. Use `summary_local_only.py` or grep to find the target location
2. Read a small window around that location
3. Use Edit to insert the new entry at the correct indentation level
4. Maintain alphabetical order within subsections when practical

### Reorganizing/Moving Entries
When moving entries between sections (e.g., Career <-> Maintenance):
1. Grep to find the exact entry and its children
2. Read small windows around source and destination locations
3. Edit to remove from source
4. Edit to add at destination with correct indentation

### Cleanup Tasks
For organizing, finding orphans, or identifying misplaced files:
1. Use `python3 utils/summary_local_only.py "## SectionName"` to list section contents
2. Cross-reference with `ls` or Glob to find files not in SUMMARY.md
3. Check for broken links by verifying paths exist

## Directory Structure

**Primary directories** (stable):
- `career/` - Professional and technical topics
- `inbox/` - Unsorted/new content
- `leisure/` - Hobbies and entertainment
- `maintenance/` - System maintenance
- `relations/` - Relationships and social topics

**Legacy directories** (old, redundant, subject to removal):
- `interface/`, `languages/`, `law/`, `lectures/`, `life/`, `math/`, `misc/`, `music/`, `psychology/`, `workflow/`, `yearly-reviews-public/`

> **Self-updating instruction**: If any directory listed above no longer exists, prompt the user and offer to update this CLAUDE.md file to remove the stale reference.

## Notes

- Use `python3` (not `python`) on this system
- MCP servers (context7, filesystem) are not required - built-in Claude Code tools handle all file operations
