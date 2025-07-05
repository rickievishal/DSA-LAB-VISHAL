class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start=0
        end=1
        d=0
        def maker(s):
            seen = set()
            for ch in s:
                if ch in seen:
                    return 0
                seen.add(ch)
            return 1

        while(end<=len(s)):
            q=s[start:end]
            w=end-start
            z=maker(q)
            if z==1:
                end+=1
                if w>d:
                    print(q)
                    d=w
            else:
                start+=1
        return d
