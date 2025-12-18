#!/usr/bin/env bash

REPO_URL="https://github.com/Aeyone/aeyone-algorithm-note"
BRANCH="main"
TEMPLATE_DIR="Template"

echo "## Template"
echo

for category in "$TEMPLATE_DIR"/*; do
    [ -d "$category" ] || continue

    cname=$(basename "$category")

    echo "<details>"
    echo "<summary><strong>$cname</strong></summary>"
    echo

    for file in "$category"/*; do
        [ -f "$file" ] || continue
        fname=$(basename "$file")
        url="$REPO_URL/blob/$BRANCH/$TEMPLATE_DIR/$cname/$fname"
        echo "- [$fname]($url)"
    done

    echo
    echo "</details>"
    echo
done

