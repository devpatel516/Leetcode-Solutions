int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    int temp, m = 0;
    for(int i = 0; i < seatsSize - 1; i++) {
        for(int j = 0; j < seatsSize - 1 - i; j++) {
            if(seats[j] > seats[j+1]) {
                temp = seats[j+1];
                seats[j+1] = seats[j];
                seats[j] = temp;
            }
        }
    }
    for(int i = 0; i < studentsSize - 1; i++) {
        for(int j = 0; j < studentsSize - 1 - i; j++) {
            if(students[j] > students[j+1]) {
                temp = students[j+1];
                students[j+1] = students[j];
                students[j] = temp;
            }
        }
    }
    for(int i = 0; i < seatsSize; i++) {
        m += abs(seats[i] - students[i]);
    }
    return m;
}
