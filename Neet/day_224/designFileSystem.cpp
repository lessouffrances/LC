class FileSystem 
{
    public:
    FileSystem() {}
    
    bool createPath(string path, int value) 
    {
        // need to see if the parent of this path exists
        int lastSlash = path.rfind('/');
        string parent = path.substr(0, lastSlash);
        string name = path.substr(lastSlash+1);

        // if this path has a parent but the parent is not in this system
        if (!parent.empty() && !pathToVal.count(parent)) return false;
        if (pathToVal.count(path)) return false;

        pathToVal[path] = value;
        return true;
    }
    
    int get(string path) 
    {
        return pathToVal.count(path) ? pathToVal[path] : -1;
    }

    private:
    unordered_map<string, int> pathToVal;
};
    
   