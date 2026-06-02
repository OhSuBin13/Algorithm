import java.util.*;

class Solution {
    static class Song {
        int id;
        int play;
        
        Song(int id, int play) {
            this.id = id;
            this.play = play;
        }
    }

    public int[] solution(String[] genres, int[] plays) {
        HashMap<String, Integer> genreTotal = new HashMap<>();
        HashMap<String, ArrayList<Song>> genreSongs = new HashMap<>();
        
        for (int i = 0; i < genres.length; i++) {
            String genre = genres[i];
            
            genreTotal.put(genre, genreTotal.getOrDefault(genre, 0) + plays[i]);
            
            genreSongs.putIfAbsent(genre, new ArrayList<>());
            genreSongs.get(genre).add(new Song(i, plays[i]));
        }
        
        ArrayList<String> genreList = new ArrayList<>(genreTotal.keySet());
        
        genreList.sort((a, b) -> genreTotal.get(b) - genreTotal.get(a));
        
        ArrayList<Integer> answer = new ArrayList<>();
        
        for (String genre : genreList) {
            ArrayList<Song> songs = genreSongs.get(genre);
            
            songs.sort((a, b) -> {
                if (b.play == a.play) {
                    return a.id - b.id;
                }
                return b.play - a.play;
            });
            
            int count = Math.min(2, songs.size());
            
            for (int i = 0; i < count; i++) {
                answer.add(songs.get(i).id);
            }
        }
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}