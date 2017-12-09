#include "boldtag.h"
#include <cassert>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Test {
    string str;
    vector<string> dict;
    string truth;
    static int idx;

public:
    Test(string str, vector<string> dict, string truth)
        : str(str), dict(dict), truth(truth) {
    }

    void run(Solution sol) {
        cout << "Test " << ++idx << " ...";
        string ans = sol.addBoldTag(str, dict);
        if (ans != truth) {
            cout << endl << "  Input: " << str << endl;
            cout << "         [ ";
            for (auto s : dict) {
                cout << s << ' ';
            }
            cout << ']' << endl;
            cout << "  Truth: " << truth << endl;
            cout << "  Ans: " << ans << endl;
            assert(ans == truth);
        }
        cout << " passed" << endl;
    }
};

int Test::idx = 0;

int main() {
    Solution sol;
    vector<Test> tests;
    tests.push_back(Test("abc", {"a", "c"}, "<b>a</b>b<b>c</b>"));
    tests.push_back(Test("abc", {"b", "c"}, "a<b>bc</b>"));
    tests.push_back(Test("abc", {"ab", "bc"}, "<b>abc</b>"));
    tests.push_back(Test("aaabbc", {"aaa", "aab", "bc"}, "<b>aaabbc</b>"));
    tests.push_back(Test("aaabbcc", {"aaa", "aab", "bc"}, "<b>aaabbc</b>c"));
    tests.push_back(Test("aaabbcc", {"aaa", "aab", "bc", "aaabbcc"}, "<b>aaabbcc</b>"));
    tests.push_back(Test("aaabbcc", {}, "aaabbcc"));
    tests.push_back(Test("aaabbcc", {"d"}, "aaabbcc"));
    tests.push_back(Test("aqbqzvwialgmmolvsnavdrwpvneljdfyuvrnjelgpbrpmsgbixvhljhowlhkbomwexaqvhhaztcsvmusfhropjpwzedccymifkmrlcfhocolkssbljmakfuezfxitpkkmuifzusfzcfvfwdvtbbqubnegbnomaquxjfmsnwzccqzthpmhkrvezweaukbuxohfagifhuyuswvdydkwrqmdjecqxblzwdjwcqxczssntyuehjbxbehsdqmqihfwaeleqpjttlgifsxwwqaeezsnslnzdnfojswswlvkfcbznzhtcjupepvrvroetsxtvyjeqwlhdmakrnbptsvppzstevhbdekluulfmwwtgdbgypq", {"aq","bq","zv","wi","al","gm","mo","lv","sn","av","dr","wp","vn","el","jd","fy","uv","rn","je","lg","pb","rp","ms","gb","ix","vh"}, "<b>aqbqzvwialgmmolvsnavdrwpvneljdfyuvrnjelgpbrpmsgbixvh</b>ljhowlhkbomwex<b>aqvh</b>haztcsvmusfhropjpwzedccymifkmrlcfhocolkssbljmakfuezfxitpkkmuifzusfzcfvfwdvtb<b>bq</b>ubne<b>gb</b>nom<b>aq</b>uxjf<b>msn</b>wzccqzthpmhkrvezweaukbuxohfagifhuyuswvdydkwrqmd<b>je</b>cqxblzwdjwcqxczs<b>sn</b>tyuehjbxbehsdqmqihfwa<b>el</b>eqpjtt<b>lg</b>ifsxwwqaeez<b>sn</b>slnzdnfojswsw<b>lv</b>kfcbznzhtcjupepvrvroetsxtvy<b>je</b>qwlhdmak<b>rn</b>bptsvppzste<b>vh</b>bdekluulfmwwtgdbgypq"));
    tests.push_back(Test("qrzjsorbkmyzzzvoqxefvxkcwtpkhzbakuufbpgdkykmojwuennrjeciqvvacpzrrczfhxnsmginzwinzihpomxtmweyyzzmgcoiupjnidphvzlnxtcogufozlenjfvokztghwckzyvmktduqkizixzxpanjwrdeudjyftxksjgdklwxrhmudhrtemuvelykqaafzlqmennttkighcdxfozdcoqkyshhajipnsdrljrnlwmyjuwxsebpqm", {"qr","zj","so","rb","km","yz","zz","vo","qx","ef","vx","kc","wt","pk"}, "<b>qrzjsorbkmyzzzvoqxefvxkcwtpk</b>hzbakuufbpgdky<b>km</b>ojwuennrjeciqvvacpzrrczfhxnsmginzwinzihpomxtmwey<b>yzz</b>mgcoiupjnidphvzlnxtcogufozlenjf<b>vo</b>kztghwckzyvmktduqkizixzxpanjwrdeudjyftxksjgdklwxrhmudhrtemuvelykqaafzlqmennttkighcdxfozdcoqkyshhajipnsdrljrnlwmyjuwxsebpqm"));

    for (auto test : tests) {
        test.run(sol);
    }
}
