#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Heap
{
    vector<int> heap;

public:
    void heapify()
    {
        int l_i = heap.size() - 1;
        int p_i = (l_i - 1) / 2;
        while (heap[p_i] > heap[l_i])
        {
            swap(heap[p_i], heap[l_i]);
            l_i = p_i;
            p_i = (l_i - 1) / 2;
        }
        return;
    }
    void down_heapify(int index)
    {

        int p = index;
        int c_l = 2 * index + 1, c_r = 2 * index + 2;
        while ((c_l < heap.size()) && (heap[c_l] < heap[p] || heap[c_r] < heap[p]))
        {
            int min_index = p;
            if (heap[c_l] < heap[p])
            {
                min_index = c_l;
            }
            if ((c_r < heap.size()) && heap[min_index] > heap[c_r])
                min_index = c_r;
            if (min_index == p)
                break;

            swap(heap[min_index], heap[p]);

            p = min_index;
            c_l = 2 * index + 1, c_r = 2 * index + 2;
        }
        return;
    }
    void Add(int k)
    {
        heap.push_back(k);
        heapify();
    }
    void deleteE(int k)
    {
        std ::vector<int>::iterator itr;
        itr = find(heap.begin(), heap.end(), k);
        int index = std::distance(heap.begin(), itr);
        swap(heap[index], heap[heap.size() - 1]);
        heap.pop_back();
        down_heapify(index);
        return;
    }
    int minE()
    {
        return heap[0];
    }
};

int main()
{
    Heap h;
    int q;
    cin >> q;
    while (q)
    {
        int q_i;
        cin >> q_i;
        if (q_i == 3)
        {
            cout << h.minE() << "\n";
        }
        else
        {
            int k;
            cin >> k;
            if (q_i == 1)
                h.Add(k);

            else
                h.deleteE(k);
        }
        q--;
    }
    return 0;
}
