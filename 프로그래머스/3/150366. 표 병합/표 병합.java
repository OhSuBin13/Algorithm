
import java.util.ArrayList;
import java.util.List;

class Solution {

  private static final int SIZE = 50;
  private static final int TOTAL = SIZE * SIZE;

  private int[] parent = new int[TOTAL];
  private String[] value = new String[TOTAL];

  public String[] solution(String[] commands) {
    List<String> answer = new ArrayList<>();

    for (int i = 0; i < TOTAL; i++) {
      parent[i] = i;
    }

    for (String command : commands) {
      String[] parts = command.split(" ");

      switch (parts[0]) {
        case "UPDATE":
          if (parts.length == 4) {
            updateCell(
                Integer.parseInt(parts[1]),
                Integer.parseInt(parts[2]),
                parts[3]);
          } else {
            updateValue(parts[1], parts[2]);
          }
          break;

        case "MERGE":
          merge(
              Integer.parseInt(parts[1]),
              Integer.parseInt(parts[2]),
              Integer.parseInt(parts[3]),
              Integer.parseInt(parts[4]));
          break;

        case "UNMERGE":
          unmerge(
              Integer.parseInt(parts[1]),
              Integer.parseInt(parts[2]));

          break;

        case "PRINT":
          answer.add(print(
              Integer.parseInt(parts[1]),
              Integer.parseInt(parts[2])));
          break;
      }
    }

    return answer.toArray(new String[0]);
  }

  private int getIndex(int r, int c) {
    return (r - 1) * SIZE + (c - 1);
  }

  private int find(int x) {
    if (parent[x] == x) {
      return x;
    }

    return parent[x] = find(parent[x]);
  }

  private void updateCell(int r, int c, String newValue) {
    int index = getIndex(r, c);
    int root = find(index);

    value[root] = newValue;
  }

  private void updateValue(String oldValue, String newValue) {
    for (int i = 0; i < TOTAL; i++) {
      if (parent[i] == i && oldValue.equals(value[i])) {
        value[i] = newValue;
      }
    }
  }

  private void merge(int r1, int c1, int r2, int c2) {
    int index1 = getIndex(r1, c1);
    int index2 = getIndex(r2, c2);

    int root1 = find(index1);
    int root2 = find(index2);

    if (root1 == root2) {
      return;
    }

    String mergedValue;

    if (value[root1] != null) {
      mergedValue = value[root1];
    } else {
      mergedValue = value[root2];
    }

    parent[root2] = root1;

    value[root1] = mergedValue;
    value[root2] = null;
  }

  private void unmerge(int r, int c) {
    int target = getIndex(r, c);
    int targetRoot = find(target);

    String savedValue = value[targetRoot];

    List<Integer> members = new ArrayList<>();

    for (int i = 0; i < TOTAL; i++) {
      if (find(i) == targetRoot) {
        members.add(i);
      }
    }

    for (int member : members) {
      parent[member] = member;
      value[member] = null;
    }

    value[target] = savedValue;
  }

  private String print(int r, int c) {
    int index = getIndex(r, c);
    int root = find(index);

    if (value[root] == null) {
      return "EMPTY";
    }

    return value[root];
  }

}