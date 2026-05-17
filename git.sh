git filter-branch -f --env-filter '
CORRECT_NAME="Siyoung Pyeon"
CORRECT_EMAIL="austin8842@naver.com"

# sipyeon@ 뒤에 임의의 문자열이 오고 .42gyeongsan.kr로 끝나는 패턴
REGEX_PATTERN="^sipyeon@.*\.42gyeongsan\.kr$"

if echo "$GIT_COMMITTER_EMAIL" | grep -qE "$REGEX_PATTERN"; then
    export GIT_COMMITTER_NAME="$CORRECT_NAME"
    export GIT_COMMITTER_EMAIL="$CORRECT_EMAIL"
fi

if echo "$GIT_AUTHOR_EMAIL" | grep -qE "$REGEX_PATTERN"; then
    export GIT_AUTHOR_NAME="$CORRECT_NAME"
    export GIT_AUTHOR_EMAIL="$CORRECT_EMAIL"
fi
' --tag-name-filter cat -- --branches --tags
