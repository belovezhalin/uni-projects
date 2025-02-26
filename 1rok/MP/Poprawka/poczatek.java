public int binsearch(int x) {
    int low = 0;
    int upp = n - 1;
    int curr;

    while(low <= upp) {
        curr = (low + upp) / 2;
        if(tab[curr] == x) {
            return curr;
        }
        else {
            if(tab[curr] < x) {
                low = curr + 1;
            }
            else {
                upp = curr - 1;
            }
        }
    }
    return n;
}

public int interpolationsearch(int x) {
    int low = 0; 
    int upp = n - 1;
    int curr;
    int p = n;

    while(a[low] <= x && x <= a[upp]) {
        curr = low + (x - a[low])*(upp - low) / (a[upp] - a[low]);
        if(a[curr] == x) {
            p = curr;
            break;
        }
        else {
            if(tab[curr] < x) {
                low = curr + 1;
            }
            else {
                upp = curr - 1;
            }
        }
    }
    return p;
}

public boolean delete(int x) {
    int j = binsearch(x);
    if(j == n) return false;
    else {
        n--;
        for(int i = j; i < n; i++) {
            a[i] = a[i + 1];
            return true;
        }
    }
}

public void insert(int x) {
    int j = n - 1;
    while(j >= 0 && x < a[j]) {
        a[j + 1] = a[j];
        j--;
    }
    a[j + 1] = x;
    n++;
}

public void nadpisanieduplikatow() {
    int i, j, k;
    for(i = 0; i < n; i++) {
        k = i + 1;
        for(j = k; j < n; j++) {
            if(a[j] != a[i]) {
            a[k] = a[j];
            k++;
            }
        }
        n = k;
    }
}

public void usuwanie() {
    int i = 0;
    while(i < n) {
        j  = i + 1;
        while(j < n) {
            if(a[i] == a[j]) {
                delete(j);
            }
            else j++;
        }
    i++;
    }
}

public void delete(int p) {
    n--;
    for(int k = p; k < n; k++) a[k] = a[k + 1];
}

public void kadane() {
    for(int i = 0; i < n; i++) {
        sum = sum + a[i];
        if(sum < 0) {
            sum = 0;
            x = i + 1;
        }
        else if(sum > max) {
            max = sum;
            start = x; 
            end = i;
        }
    }
}

public void sortn2() {
    for(i = 0; i < n; i++) {
        sum = 0;
        for(j = i; j < n; j++) {
            sum = sum + a[j];
            if(sum > max) {
               max = sum;
               start = i; 
               end = j;
            }
        }
    }
}

public void sortn3() {
    for(i = 0; i < n; i++) {
        for(j = i; j < n; j++) {
            sum = 0; 
            for(k = i; k <= j; k++) {
                sum = sum + a[k];
            }
            if(sum > max) {
               max = sum;
               start = i; 
               end = j;
            }
        }
    }
}

public void insertionsort() {
    for(int j = 1; j < n; j++) {
        tmp = a[j];
        i = j - 1;
        while(i >= 0 && tmp < a[i]) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = tmp;
    }
}