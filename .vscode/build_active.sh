#!/usr/bin/env bash
set -euo pipefail

src="${1:?Open a source file first}"
project="${2:?Project folder is required}"
build_dir="$project/build"

mkdir -p "$build_dir"

filename="$(basename "$src")"
program="${filename%.*}"

case "$src" in
    *.c)
        compiler=(gcc -std=c11)
        ;;
    *.cpp|*.cc|*.cxx)
        compiler=(g++ -std=c++17)
        ;;
    *.py)
        exec python3 "$src"
        ;;
    *)
        echo "Unsupported file type: $src" >&2
        exit 2
        ;;
esac

"${compiler[@]}" -Wall -Wextra -Wpedantic -g \
    "$src" -o "$build_dir/$program"

"$build_dir/$program"
