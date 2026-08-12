class Solution {

  private final int[] DISCOUNTS = { 10, 20, 30, 40 };

  private int maxSubscribers = 0;
  private int maxSales = 0;

  public int[] solution(int[][] users, int[] emoticons) {
    int[] discountRates = new int[emoticons.length];

    dfs(0, discountRates, users, emoticons);
    return new int[] { maxSubscribers, maxSales };
  }

  private void dfs(int depth, int[] discountRates, int[][] users, int[] emoticons) {
    if (depth == emoticons.length) {
      calculate(discountRates, users, emoticons);
      return;
    }

    for (int discount : DISCOUNTS) {
      discountRates[depth] = discount;
      dfs(depth + 1, discountRates, users, emoticons);
    }
  }

  private void calculate(int[] discountRates, int[][] users, int[] emoticons) {
    int subscribers = 0;
    int sales = 0;

    for (int[] user : users) {
      int minDiscount = user[0];
      int limitPrice = user[1];

      int totalPrice = 0;

      for (int i = 0; i < emoticons.length; i++) {
        if (discountRates[i] >= minDiscount) {
          totalPrice += emoticons[i] * (100 - discountRates[i]) / 100;
        }
      }

      if (totalPrice >= limitPrice) {
        subscribers++;
      } else {
        sales += totalPrice;
      }
    }

    if (subscribers > maxSubscribers) {
      maxSubscribers = subscribers;
      maxSales = sales;
    } else if (subscribers == maxSubscribers && sales > maxSales) {
      maxSales = sales;
    }
  }
}