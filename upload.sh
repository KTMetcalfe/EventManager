#!/bin/bash
echo -e '\033[0;34m'Uploading server files...'\033[0m'
rsync -avzh --no-p ./Server root@10.0.0.10:/mnt/user/eventmanager/
echo -e '\033[0;36m'Server files uploaded.'\033[0m'