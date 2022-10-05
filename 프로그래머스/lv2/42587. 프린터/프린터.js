function solution(pri, location) {
    let arr = [];
    let answer = [];
    let lo = 0;
    pri.forEach((e,idx) => arr.push({e,idx}));
    pri.sort((a,b) => b-a);
    while(arr.length){
        let J = arr.shift();
        if(pri[0] === J.e) {
            answer.push(J);
            pri.shift()
        }
        else arr.push(J)
    }
    answer.forEach((e,i) => {
        if(e.idx === location) lo = i+1
    })
    return lo
}