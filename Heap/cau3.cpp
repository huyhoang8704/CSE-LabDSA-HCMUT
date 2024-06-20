void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    while(index < numberOfElements/2){
        int k  = index;
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        if(maxHeap[left] > maxHeap[index]) index = left;
        if(maxHeap[right] > maxHeap[index]) index = right;
        if(index != left && index != right) return;
        else swap(maxHeap[k],maxHeap[index]);
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    while(index > 0){
        int parent = (index - 1) / 2;
        if(maxHeap[index] < maxHeap[parent]) return;
        
        swap(maxHeap[index], maxHeap[parent]);
        index = parent;
    }   
}