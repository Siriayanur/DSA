
class Platform
{
    static int findPlatform(int arr[], int dep[], int n)
    {
        // add your code here
        Arrays.sort(arr);
        Arrays.sort(dep);
        int platforms = 1, j = 0, i = 1, totalPlatforms = 1;
        while(i < n && j < n){
            if(arr[i] <= dep[j]){
                platforms++;
                i++;
                if(platforms > totalPlatforms){
                    totalPlatforms = platforms;
                }
            } else {
               j++;
               platforms--;
            }
        }
        
        return totalPlatforms;
    }
    
}