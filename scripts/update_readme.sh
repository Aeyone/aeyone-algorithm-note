#!/usr/bin/env bash

TMP=$(mktemp)

scripts/gen_template_readme.sh > "$TMP"

sed -i "/<!-- TEMPLATE_START -->/,/<!-- TEMPLATE_END -->/{
    /<!-- TEMPLATE_START -->/{
        p
        r $TMP
    }
    /<!-- TEMPLATE_END -->/p
    d
}" README.md

rm "$TMP"

