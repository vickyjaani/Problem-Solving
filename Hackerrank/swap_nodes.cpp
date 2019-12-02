#include <bits/stdc++.h>

using namespace std;

void inorder(vector<vector<int>> indexes, vector<int> &temp, int i = 0)
{
    int left = indexes[i][0] - 1;
    int right = indexes[i][1] - 1;

    if (left != -2)
        inorder(indexes, temp, left);
    temp.push_back(i + 1);
    if (right != -2)
        inorder(indexes, temp, right);
    return;
}
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries)
{
    vector<vector<int>> depth;
    depth.push_back(std::vector<int>());
    int n = indexes.size();
    queue<int> myq;
    myq.push(0);
    int level = 0;
    int level_nodes = 1;
    int temp_level_nodes = 0;
    for (int i = 0; i < n; i++)
    {
        int f = myq.front();
        depth[level].push_back(f);
        if (indexes[f][0] != -1)
        {
            myq.push(indexes[f][0] - 1);
            temp_level_nodes++;
        }
        if (indexes[f][1] != -1)
        {
            myq.push(indexes[f][1] - 1);
            temp_level_nodes++;
        }
        myq.pop();
        level_nodes--;
        if (level_nodes == 0)
        {
            level_nodes = temp_level_nodes;
            temp_level_nodes = 0;
            level++;
            depth.push_back(std ::vector<int>());
        }
    }
    n = queries.size();
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++) // swaping
    {
        for (int j = queries[i] - 1; j < level; j += queries[i])
        {
            int nodes = depth[j].size();
            for (int k = 0; k < nodes; k++)
            {
                swap(indexes[depth[j][k]][0], indexes[depth[j][k]][1]);
            }
        }
        vector<int> temp;
        inorder(indexes, temp);
        ans[i] = temp;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++)
    {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++)
        {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++)
    {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);
    //cout << " test";
    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++)
    {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++)
        {
            cout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1)
            {
                cout << " ";
            }
        }

        if (result_row_itr != result.size() - 1)
        {
            cout << "\n";
        }
    }

    cout << "\n";

    //fout.close();

    return 0;
}
