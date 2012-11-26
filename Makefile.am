bin_PROGRAMS = esl
esl_CFLAGS =
esl_LDFLAGS =
esl_SOURCES = src/main.cpp

scrub:
	@files="$($SHELL git ls-files --other --exclude-standard 2>/dev/null)";\
                                                                              \
	if ! [ -z "$$files" ]; then                                           \
		echo "Scrub aborted: there are untracked files in the repo";  \
	else                                                                  \
		git clean -xfd;                                               \
	fi

check:
