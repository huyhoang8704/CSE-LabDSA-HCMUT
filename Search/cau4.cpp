bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2)
{
    // Create an empty Hash to store mapping from sum to
    // pair indexes
    map<int, pair<int, int> > Hash;
 
    // Traverse through all possible pairs of arr[]
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            // If sum of current pair is not in hash,
            // then store it and continue to next pair
            int sum = arr[i] + arr[j];
            if (Hash.find(sum) == Hash.end())
                Hash[sum] = make_pair(i, j);
 
            else // Else (Sum already present in hash)
            {
                // Find previous pair
                pair<int, int> pp = Hash[sum];
                pair1 = {arr[pp.first],arr[pp.second]};
                pair2 = {arr[i],arr[j]};
                return true;
            }
        }
    }
 
    return false;
   
}