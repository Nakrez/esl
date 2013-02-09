#! /bin/sh

categorie="esl"
count=8
curr=1
win=0

while test $curr -le $count; do
    file=$categorie$curr".esl"
    ./esl "./check/$categorie/$file" > ./check/$categorie/out
    if diff "./check/$categorie/out" "./check/$categorie/out$curr" > /dev/null; then
        win=$(($win+1))
    else
        echo "File $file in $categorie failed"
        exit 1
    fi
    curr=$(($curr+1));
done

rm -f ./check/$categorie/out
echo "Categorie $categorie passed $win/$count"
