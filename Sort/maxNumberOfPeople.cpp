int maxNumberOfPeople(vector<int> &rooms, vector<int> &people, int k)
{
    std::sort(rooms.begin(), rooms.end());
    std::sort(people.begin(), people.end());

    int i = 0, j = 0, count = 0;
    while (i < rooms.size() && j < people.size())
    {
        if (abs(rooms[i] - people[j]) <= k)
        {
            i++;
            j++;
            count++;
        }
        else if (rooms[i] < people[j] - k)
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return count;
}