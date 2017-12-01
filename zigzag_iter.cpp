#include <vector>
#include <list>
#include <utility>

using std::vector;
using std::list;
using std::pair;

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) : _hasNext(false) {
        it_pair p1(v1.begin(), v1.end());
        it_pair p2(v2.begin(), v2.end());
        vlist.push_back(p1);
        vlist.push_back(p2);
        vlist_it = vlist.begin();
        prepare();
    }

    int next() {
        int ret = _next;
        prepare();
        return ret;
    }

    bool hasNext() {
        return _hasNext;
    }

private:
    using it_pair = pair<vector<int>::iterator, vector<int>::iterator>;
    list<it_pair> vlist;
    list<it_pair>::iterator vlist_it;

    bool _hasNext;
    int _next;

    void prepare() {
        while (!vlist.empty() && vlist_it->first == vlist_it->second) {
            // empty or exhausted vector, remove from list
            vlist_it = vlist.erase(vlist_it);
            if (vlist_it == vlist.end())
                vlist_it = vlist.begin(); // wrap around
        }
        if (vlist.empty()) {
            _hasNext = false;
            return;
        }
        _hasNext = true;
        _next = *((vlist_it->first)++);
        if (++vlist_it == vlist.end()) // wrap around vlist if reach the end
            vlist_it = vlist.begin();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
