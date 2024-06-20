class PrinterQueue
{
public:

    string maxHeap[200];
    int size = 0;
    
public:
    PrinterQueue(){
        for(int i = 0 ; i < 200; i++){
            maxHeap[i] = "";
        }
    }



    void addNewRequest(int priority, string fileName)
    {
        if(maxHeap[priority] == "") maxHeap[priority] = fileName;
        else maxHeap[priority] += " " + fileName;
    }

    void print()
    {
        for(int i = 200 - 1 ; i >= 0; i--){
            if(maxHeap[i] != ""){
                int index = maxHeap[i].find(" ");
                if(index == -1){
                    cout << maxHeap[i] << endl;
                    maxHeap[i] = "";
                }
                else{
                    cout << maxHeap[i].substr(0,index) << endl;
                    maxHeap[i] = maxHeap[i].substr(index+1);
                }
                return;
            }
        }
        cout << "No file to print" << endl;
    }

    
};