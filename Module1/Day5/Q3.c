#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time calculateTimeDifference(const struct Time* startTime, const struct Time* endTime) {
    struct Time difference;
    
    int startSeconds = startTime->hours * 3600 + startTime->minutes * 60 + startTime->seconds;
    int endSeconds = endTime->hours * 3600 + endTime->minutes * 60 + endTime->seconds;
    
    int totalSeconds = endSeconds - startSeconds;
    if (totalSeconds < 0) {
        totalSeconds *= -1;
    }
    
    difference.hours = totalSeconds / 3600;
    totalSeconds %= 3600;
    difference.minutes = totalSeconds / 60;
    difference.seconds = totalSeconds % 60;
    
    return difference;
}

int main() {
    struct Time startTime, endTime, difference;
    
    printf("Enter the start time:\n");
    printf("Hours: ");
    scanf("%d", &(startTime.hours));
    printf("Minutes: ");
    scanf("%d", &(startTime.minutes));
    printf("Seconds: ");
    scanf("%d", &(startTime.seconds));
    
    printf("\nEnter the end time:\n");
    printf("Hours: ");
    scanf("%d", &(endTime.hours));
    printf("Minutes: ");
    scanf("%d", &(endTime.minutes));
    printf("Seconds: ");
    scanf("%d", &(endTime.seconds));
    
    difference = calculateTimeDifference(&startTime, &endTime);
    
    printf("\nTime Difference: %02d:%02d:%02d\n", difference.hours, difference.minutes, difference.seconds);
    
    return 0;
}
