#!/bin/bash 
cat >test/.overlord.yaml <<EOL
---
projects:
  -
    uid: ov
    dir: $(pwd)
    run: $(pwd)/bin/ov
    build: make -C $(pwd)
EOL