# Programming language C++

# Let n = length of the array with fares


// Custom compare compares based on the sum of the fares
struct MyCompare
{
    bool operator()(const pair<int, int>& left, const pair<int, int>& right)
    {
        // Compares based on the sum of fare, less fare is given the higher priorty
        if(left.first == right.first){
          return left.second < right.second
        }else{
          return left.first < left.second
        }
    }
};

void printCheapestFlights(vector<int> & delhi_to_mumbai, vector<int>& mumbai_to_delhi, int k){
  priority_queue <pair<int, int>, vector<pair<int, int>>, MyCompare> myqueue;

  for(int i=0 ; i<delhi_to_mumbai.size(); i++){
    // Queue will store the pair of (sum of fares) and (index to maintain relative order)
    myqueue.emplace(make_pair((delhi_to_mumbai[i]+ mumbai_to_delhi[i]), i));
    if(myqueue.size > k){
      myqueue.pop();
    }   
  }
  // Prints the queue data in ascending order of the fare sum and incase of same fare in relative order.
  while(!myqueue.empty()){
    cout << delhi_to_mumbai[myqueue.top().second] << " " << mumbai_to_delhi[myqueue.top().second] <<endl;
    myqueue.pop();
  }
}

// Time complexity
// 1. To make pair and enqueue in priority queue O(n)
// To maintain a priority queue of size k O(k)
// Overall Time Complexity = O(nlog(k))

// Space Complexity 
// Total Space complexity to main the priority queue of size k+1 = O(K)
// Overall Time Complexity = O(k)