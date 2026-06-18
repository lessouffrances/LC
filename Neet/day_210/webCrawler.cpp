class Solution 
{
    public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) 
    {
        if (startUrl.empty()) return {};
        hostname = getHostname(startUrl);
        dfs(startUrl, htmlParser);
        return res;
    }

    private:
    vector<string> res;
    string hostname = "";
    unordered_set<string> visited;
    string getHostname(const string& url)
    {
        // "http://news.yahoo.com/news/topics/" -> "news.yahoo.com"
        string prefix = "http://";
        int startIdx = prefix.length();
        int endIdx = url.find('/', startIdx);
        return url.substr(startIdx, endIdx-startIdx);
    }

    void dfs(const string& startUrl, HtmlParser htmlParser)
    {
        res.push_back(startUrl);
        visited.insert(startUrl);

        for (auto& v : htmlParser.getUrls(startUrl))
        {
            if (visited.count(v)) continue;
            if (getHostname(v) != hostname) continue;
            dfs(v, htmlParser);
        }
    }    
};