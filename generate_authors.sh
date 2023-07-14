#!/bin/bash
#source: https://github.com/docker/docker/blob/master/hack/generate-authors.sh

set -e

#cd "$(dirname "$(readlink -f "$BASH_SOURCE")")/.."

{
	cat <<-'EOH'
	# This file lists all individuals who made any contributions to this repository.
	EOH
	echo
	git log --format='%aN <%aE>' | LC_ALL=C.UTF-8 sort -uf
} > AUTHORS
