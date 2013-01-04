#! /bin/sh

categorie="control"
count=7
curr=1
win=0

while test $curr -le $count; do
    file=$categorie$curr".esl"
    ./esl "./check/$categorie/$file" > ./check/out
    if diff "./check/out" "./check/$categorie/out$curr" > /dev/null; then
        win=$(($win+1))
    else
        echo "File $file in $categorie failed"
        exit 1
    fi
    curr=$(($curr+1));
done

echo "Categorie $categorie passed $win/$count"
