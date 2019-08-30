void quiclsort(Item *V, int l, int t, int ps) {
    if(ps > 2*lg(r)) {
        return;
    }
    if( r-l > m) {
        compexch(v[l], v[x]);
        compexch(v[l+1/2], v[l]);
        int i = separa(v, l, r);
        if(i-1-l > r-i+1) {
            quicksort(v, l, i-1, ps+1);
            quicksort(v, i+1, r, ps+1);
        } else {
            quicksort(v, i+1, r, ps+1);
            quicksort(v, l, i-1, ps+1);
        }
    }
}

int separa(Item * v, int l, int r) {
    Item c = v[r];
    int j=l;

    for(int i=l; i < r; i++) {
        if(lesseq(v[i], c)) {
            exch(v[i, c[j]]);
            j++;
        }
    }
    exch(v[i], v[r]);
    return j;
}

void sort(Item * v, l, r) {
    quicksort(v, l, r, 0);
    insertion(v, l, r);
}