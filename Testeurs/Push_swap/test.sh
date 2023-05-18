ITER=100;
ITERM=100;
MOYENNE=0;
NBR=0;

#modification ici :#
MINI=-100000;
MAXI=100000;
NBR_OF_NBRS=500;


while [ $ITER -gt 0 ]
do
	echo $ITER;
   NBR=$(ARG=$(seq $(( $MINI )) $MAXI | shuf -n $NBR_OF_NBRS | xargs); ./push_swap $ARG | wc -l);
   MOYENNE=$(( MOYENNE + NBR ));
   ITER=$((ITER-1));
done
MOYENNE=$(( MOYENNE / $ITERM));

echo "Votre moyenne est $MOYENNE";