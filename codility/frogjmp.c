int solution(int X, int Y, int D) {
    int steps = 0;
    if (Y > X)
    {
        steps += (Y-X)/D;
        steps += ((Y-X)%D) ? 1 : 0;
    }

    return steps;
}

