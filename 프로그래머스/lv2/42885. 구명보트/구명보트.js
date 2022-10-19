function solution(people, limit) {
    let answer = 0;
    let front = -1,back = people.length;
    people.sort((a,b) => a-b);
    while(people.length){
        if(people[0] + people.pop() <= limit) people.shift();
        answer++;
    }
    return answer
}