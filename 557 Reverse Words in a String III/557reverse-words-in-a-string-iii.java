class Solution {
    public String reverseWords(String s) {
        String w[]=s.split("\\s+");
        String res="";
        for(int i=0;i<w.length;i++){
            int l=0;
            int r=w[i].length()-1;
            char[] word=w[i].toCharArray();
            while(l<r){
                char temp=word[l];
                word[l]=word[r];
                word[r]=temp;
                l++;
                r--;
            }
        res+=new String(word);
        res+=" ";
        }
        return res.trim();
    }
}