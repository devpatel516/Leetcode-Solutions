int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int numRescueBoats(int* people, int peopleSize, int limit) {
    qsort(people, peopleSize, sizeof(int),compare);
    long left,right,sum,b=0;
    left=0;
    right=peopleSize-1;
    while(left<=right){
        sum=people[left]+people[right];
    if(sum<=limit){
        left++;
        right--;
    }
    else{
        right--;
    }
    b++;
    }
    return b;
}