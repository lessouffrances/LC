// this is a question asking for all the urls that can be reached 
// from the given url

class Solution 
{
    public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) 
    {
        if (startUrl.length() == 0) return {};
        hostname = getHostname(startUrl);
        dfs(startUrl, htmlParser);
        return res;
    }

    private:
    vector<string> res;
    string hostname = "";
    unordered_set<string> visited;
    void dfs(const string& startUrl, HtmlParser htmlParser)
    {
        res.push_back(startUrl);
        visited.insert(startUrl);

        for (auto& v : htmlParser.getUrls(startUrl)) {
            if (visited.count(v)) continue;
            if (getHostname(v) != hostname) continue; // stay on same domain
            dfs(v, htmlParser);
        }
    }

    string getHostname(const string& url) 
    {
        // "http://news.yahoo.com/news/topics/" -> "news.yahoo.com"
        string prefix = "http://";
        int start = prefix.length();
        int end = url.find('/', start);
        return url.substr(start, end - start);
    }
};