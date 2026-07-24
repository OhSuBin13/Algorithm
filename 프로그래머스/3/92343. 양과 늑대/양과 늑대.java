class Solution {

    private int[] info;
    private int[] childMask;
    private int maxSheep;

    public int solution(int[] info, int[][] edges) {
        this.info = info;
        this.childMask = new int[info.length];

        for (int[] edge : edges) {
            int parent = edge[0];
            int child = edge[1];

            childMask[parent] |= 1 << child;
        }

        dfs(0, 0, 1);
        return maxSheep;
    }

    private void dfs(int sheep, int wolf, int availableMask) {
        for (int node = 0; node < info.length; node++) {
            int nodeBit = 1 << node;

            if ((availableMask & nodeBit) == 0)
                continue;

            int nextSheep = sheep;
            int nextWolf = wolf;

            if (info[node] == 0)
                nextSheep++;
            else
                nextWolf++;

            if (nextWolf >= nextSheep)
                continue;

            maxSheep = Math.max(maxSheep, nextSheep);

            int nextAvailableMask = (availableMask & ~nodeBit) | childMask[node];

            dfs(nextSheep, nextWolf, nextAvailableMask);
        }
    }
}