#!/bin/bash
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

ENABLE_HOOKS=true
while getopts deh flag
do
	case "${flag}" in
		d) ENABLE_HOOKS=false
			;;
		e) ENABLE_HOOKS=true
			;;
		*)
			printf "Usage: %s [-d|-e]\n" $(basename "$0")
			printf "    -e : enable hooks (default)\n"
			printf "    -d : disable hooks\n"
			exit 0
			;;
	esac
done

if [ "${ENABLE_HOOKS}" = true ]; then
	echo Enabling local repository git hooks..
	git config --local core.hooksPath "${SCRIPT_DIR}/../.githooks"
else
	echo Disabling local repository git hooks..
	git config --local --unset core.hooksPath
fi
