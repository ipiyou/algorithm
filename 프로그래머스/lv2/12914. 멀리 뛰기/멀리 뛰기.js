function solution(n) {
    let answer = [1n, 1n, 2n];
    for(let i = 3; i <= n; i++) {
        answer.push(answer[i - 1] + answer[i - 2]);
    }
    return answer[n] % 1234567n;
}