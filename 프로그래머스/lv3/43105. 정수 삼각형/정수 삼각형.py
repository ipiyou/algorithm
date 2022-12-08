def solution(triangle):
    answer = 0
    Len = len(triangle)-1
    triangle[1][0] += triangle[0][0];
    triangle[1][1] += triangle[0][0];
    for i,ele in enumerate(triangle[2:],2):
        for j,child in enumerate(ele):
            if(j-1 < 0):
                triangle[i][j] += triangle[i-1][j];
            elif(j+1 >= len(ele)):
                triangle[i][j] += triangle[i-1][j-1];
            else:
                triangle[i][j] += max(triangle[i-1][j],triangle[i-1][j-1]);
    return max(triangle[Len])