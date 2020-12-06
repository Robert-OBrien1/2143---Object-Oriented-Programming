// Two simple fixes were needed to correct the swap method.
// We did not need to decrease the size of hand by 1 when comparing
// index of j to the size of hand. Therefore we do not need to incrememnt the 
// the card being swapped in the jth position by "Cards[j+1]". Revert to "Cards[j]"
void Hand::Sort(){

    // Index "i" 
    for(int i=0;i<Size();i++){
        // Index "j"
        for(int j=i;j<Size();j++){
            //Comparing cards at position i and j 
            if(Cards[i]->rank > Cards[j]->rank){
                cout<<"swapping"<<endl;

                // standard swap 
                Card* temp = Cards[i];
                Cards[i] = Cards[j];
                Cards[j] = temp;
            }
        }
    }
}
