#include<stdio.h>
#include<string.h>
#define balls 12

struct player{
	char player_name[30];
	int ball_score[balls];
	int total_score;
};
int validate_score(int score){
	return(score>=0 || score<=6);
}
void play_game(struct player *player){
	printf("enter scores for %s:\n",player->player_name);
	player->total_score=0;
	for(int i=0;i<balls;i++){
		int score;
		printf("ball %d: ",i+1);
		scanf("%d",&score);
		if(validate_score(score)){
		player->ball_score[i]=score;
		player->total_score+=score;
		}else{
			printf("invalid score! ball marked but no runs added\n");
			player->ball_score[i]=0;
		}
	}
}	
void find_winner(struct player player1,struct player player2){
	printf("match results\n");
	if(player1.total_score>player2.total_score){
		printf("winner: %s win with %d runs\n",player1.player_name,player1.total_score);
	}else if(player2.total_score>player1.total_score){
			printf("winner: %s win with %d runs\n",player2.player_name,player2.total_score);
	}else{
		printf("match is draw with %d runs\n",player1.total_score);
	}
}
void matchScoreBoard(struct player player1,struct player player2){
	printf("match scoreboard\n");
	printf("\n%s performance:\n",player1.player_name);
	printf("score:\n");
	for(int i=0;i<balls;i++){
		printf("ball %d:%d\n",i+1,player1.ball_score[i]);
	}
		int avg1=player1.total_score/12;
	printf("total score: %d\n",player1.total_score);
	printf("average score: %d\n",avg1);
		
	printf("\n%s performance:\n",player2.player_name);
	printf("score:\n");	
	for(int i=0;i<balls;i++){
		printf("ball %d:%d\n",i+1,player2.ball_score[i]);
	}
	int avg2=player2.total_score/12;
	printf("total score: %d\n",player2.total_score);
	printf("average score: %d\n",avg2);
}
int main(){
	struct player player1,player2;
	
	printf("enter player 1's name\n");
	fgets(player1.player_name,30,stdin);
	strtok(player1.player_name, "\n");
	
	printf("enter player 2's name\n");
	fgets(player2.player_name,30,stdin);
	strtok(player2.player_name, "\n");
	
	play_game(&player1);
	play_game(&player2);
	
	matchScoreBoard(player1,player2);
	
	find_winner(player1,player2);
	
	return 0;	
}
