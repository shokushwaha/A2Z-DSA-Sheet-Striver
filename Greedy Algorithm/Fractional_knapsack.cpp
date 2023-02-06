double fractionalKnapsack(int W, Item arr[], int n)
{

    vector<pair<double, int>> temp; // <value/weight,index>

    for (int i = 0; i < n; i++)
    {
        double x = (arr[i].value * 1.0) / (arr[i].weight * 1.0);
        temp.push_back({x, i});
    }

    // sorting vector in descending order
    sort(temp.begin(), temp.end(), greater<pair<double, int>>());

    // storing weight already taken
    int curr_wght = 0;

    // storing total sum
    double sum = 0;

    for (int i = 0; i < temp.size(); i++)
    {
        if (curr_wght + arr[temp[i].second].weight < W)
        {
            sum += arr[temp[i].second].value;
            curr_wght += arr[temp[i].second].weight;
        }
        else
        {
            double x = (W - curr_wght) * 1.0;
            sum += x * temp[i].first;
            break;
        }
    }

    return sum;
}