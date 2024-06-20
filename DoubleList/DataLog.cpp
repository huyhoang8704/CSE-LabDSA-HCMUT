#include<iostream>
#include <list>

using namespace std;

class DataLog
{
private:
    list<int> logList;
    list<int>::iterator currentState;

public:
    DataLog();
    DataLog(const int &data);
    void addCurrentState(int number);
    void subtractCurrentState(int number);
    void save();
    void undo();
    void redo();

    int getCurrentStateData()
    {
        return *currentState;
    }
    
    void printLog()
    {      
        for (auto i = logList.begin(); i != logList.end(); i++) {
            if(i == currentState) cout << "Current state: ";
            cout << "[ " << *i << " ] => ";
        }
        cout << "END_LOG";
    }
};

DataLog::DataLog()
{
    /*
     * TODO:  add the first state with 0
     */
    logList.push_front(0);
    currentState = logList.begin();
}

DataLog::DataLog(const int &data)
{
    /*
     * TODO:  add the first state with data
     */
    logList.push_front(data);
    currentState = logList.begin();
    
}

void DataLog::addCurrentState(int number)
{
    *currentState += number; 
}

void DataLog::subtractCurrentState(int number)
{
    /*
     * TODO: Decrease the value of current state by number
     */
    *currentState -= number;
}

void DataLog::save()
{
    /*
     * TODO: This function will create a new state, copy the data of the currentState
     *       and move the currentState Iterator to this new state. If there are other states behind the 
     *       currentState Iterator, we delete them all before creating a new state.
     */
 //! Di chuyển con trỏ currentState lên một bước để trỏ tới phần tử tiếp theo trong danh sách.
     currentState++;
//! Kiểm tra nếu currentState không trỏ tới cuối danh sách.     
     if(currentState != logList.end()){
         list<int>::iterator curr = currentState;
         list<int>::iterator prev = currentState;
        while(curr != logList.end()){
            curr++;
            logList.erase(prev);
            prev = curr;
        }
        currentState = logList.end();
       
    }
    currentState--;
  
    logList.push_back(*currentState);
    currentState++;
     for (auto i = logList.begin(); i != logList.end(); i++) {
            cout << "[ " << *i << " ] => ";
        }
        cout<<endl;

}

void DataLog::undo()
{
    /*
     * TODO: Switch to the previous state of the data
     *       If this is the oldest state in the log, nothing changes
     */
    if(currentState != logList.begin())
        --currentState;
}
void DataLog::redo()
{
    /*
     * TODO: Switch to the latter state of the data
     *       If this is the latest state in the log, nothing changes
     */
     ++currentState;
    if(currentState == logList.end()) --currentState;
  
    
}
   

int main(){
    DataLog log(10);
    log.save();
    log.addCurrentState(15);
    log.save();
    log.addCurrentState(15);
    log.undo();
    log.printLog();
//! [ 10 ] => Current state: [ 25 ] => [ 40 ] => END_LOG
cout<<endl;
    DataLog log1(10);
    log1.save();
    log1.addCurrentState(15);
    log1.save();
    log1.addCurrentState(15);
    log1.save();
    log1.subtractCurrentState(5);
    log1.printLog();
    
// //! [ 10 ] => [ 25 ] => [ 40 ] => Current state: [ 35 ] => END_LOG
}
