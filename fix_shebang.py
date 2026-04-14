#!/usr/bin/env python3
"""Move shebang to line 1, preserve all other content including license headers."""
import os
import stat
import re

BASE_DIR = "/home/haplessidiot/Documents/sonicd"

def find_shebang(lines):
    """Find shebang in first 20 lines, return (line_index, shebang_content) or None."""
    for i, line in enumerate(lines[:20]):
        if line.strip().startswith('#!'):
            return i, line.strip()
    return None

def fix_file(filepath):
    try:
        with open(filepath, 'r') as f:
            lines = f.readlines()

        if not lines:
            return False

        # Find existing shebang
        result = find_shebang(lines)
        if result is None:
            return False  # No shebang found
        shebang_idx, shebang = result
        if shebang_idx == 0:
            return False  # Shebang already at line 1

        # Determine new shebang based on extension
        ext = os.path.splitext(filepath)[1]
        if ext == '.py':
            new_shebang = '#!/usr/bin/env python3'
        elif ext == '.sh':
            new_shebang = '#!/usr/bin/env bash'
        else:
            new_shebang = shebang  # Keep original

        # Remove old shebang line and add new one at position 0
        new_lines = [new_shebang + '\n']
        new_lines.extend(lines[:shebang_idx])  # License lines before shebang
        new_lines.extend(lines[shebang_idx+1:])  # Everything after old shebang

        with open(filepath, 'w') as f:
            f.writelines(new_lines)

        # Ensure executable bit
        st = os.stat(filepath)
        os.chmod(filepath, st.st_mode | stat.S_IXUSR | stat.S_IXGRP | stat.S_IXOTH)

        print(f"Fixed: {filepath} (shebang moved to line 1)")
        return True

    except Exception as e:
        print(f"Error processing {filepath}: {e}")
    return False

def main():
    print(f"Starting recursive shebang fix in: {BASE_DIR}")
    for root, dirs, files in os.walk(BASE_DIR):
        # Skip .git directory
        if '.git' in dirs:
            dirs.remove('.git')
        for name in files:
            if name.endswith('.py') or name.endswith('.sh'):
                full_path = os.path.join(root, name)
                # Don't fix this script itself
                if "fix_shebang.py" not in name:
                    fix_file(full_path)

    print("\nDone! All shebangs moved to line 1.")

if __name__ == '__main__':
    main()