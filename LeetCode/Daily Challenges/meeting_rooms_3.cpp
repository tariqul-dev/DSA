#include <bits/stdc++.h>

using namespace std;

int mostBooked(int n, vector<vector<int>> &meetings)
{
    int m = meetings.size();

    sort(meetings.begin(), meetings.end());

    vector<long long> lastAvailableAt(n, 0);
    vector<int> roomUsedCount (n, 0);

    for(vector<int> &meet: meetings){
        int startTime = meet[0];
        int endTime = meet[1];
        int duration = endTime - startTime;

        bool isAvailableRoomFound = false;

        long long earlyEndRoomTime = LLONG_MAX;
        int earlyEndRoom = 0;

        for(int room = 0; room < n; room++){
            if (lastAvailableAt[room] <= startTime ){
                lastAvailableAt[room] = endTime;
                roomUsedCount[room]++;
                isAvailableRoomFound = true;
                break;
            }


            if (lastAvailableAt[room] < earlyEndRoomTime){
                earlyEndRoomTime = lastAvailableAt[room];
                earlyEndRoom = room;
            }
        }

        // if no room found
        if (!isAvailableRoomFound){
            lastAvailableAt[earlyEndRoom] += duration;
            roomUsedCount[earlyEndRoom]++;
        }
    }

    int maxUsedRoomCount = 0;
    int maxUsedRoom = -1;

    for (int room = 0; room < n; room++){
        if (roomUsedCount[room] > maxUsedRoomCount){
            maxUsedRoomCount = roomUsedCount[room];
            maxUsedRoom = room;
        }
    }

    return maxUsedRoom;
}

int main()
{
    int n = 3;
    vector<vector<int>> meetings = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};

    cout << mostBooked(n, meetings) << endl;

    return 0;
}