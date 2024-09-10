import sys

def parse(section_title: str, path_to_file: str):
    def extract_titles(content, section_name):
        titles = []
        capture = False

        for line in content.splitlines():
            if section_name in line:
                capture = True
            elif line.startswith("## "):  # Stop capturing if a new section starts
                capture = False

            if capture and '[' in line and ']' in line:
                title = line.split('[')[1].split(']')[0]  # Extract text inside []
                if not line.startswith("http"):  # Skip URLs
                    titles.append(title)

        return titles

    def print_tree(titles, indent=0):
        for title in titles:
            print('  ' * indent + f'* {title}')
            # For simplicity, assuming there's no deeper nesting in this example

    try:
        with open(path_to_file, 'r') as file:
            content = file.read()
    except FileNotFoundError:
        print(f"Error: File '{path_to_file}' not found.")
        return

    titles = extract_titles(content, section_title)
    print_tree(titles)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python script.py <section_title> <path_to_file>")
    else:
        section_title = sys.argv[1]
        path_to_file = sys.argv[2]
        parse(section_title, path_to_file)
