struct Trie {
  Trie * child[26];
  bool leaf;
};

Trie * createNode() {
  Trie * link = (Trie * ) malloc(sizeof(Trie));
  for (ll i = 0; i < 26; i++) {
    link -> child[i] = NULL;
  }
  link -> leaf = false;
  return link;
}

void insertWord(Trie * root, string s) {
  Trie * ptr = root;
  for (char c: s) {
    int n = c - 'a';
    if (ptr -> child[n] == NULL) {
      ptr -> child[n] = createNode();
    }
    ptr = ptr -> child[n];
  }
  ptr -> leaf = true;
}

bool searchWord(Trie * root, string s) {
  for (char c: s) {
    int i = c - 'a';
    if (root -> child[i]) {
      root = root -> child[i];
    }
  }
  return (root -> leaf);
}

void print(Trie * ptr) {
  for (int i = 0; i < 26; i++) {
    if (ptr -> child[i]) {
      cout << (char)(i + 'a') << ' ';
      print(ptr -> child[i]);
    }
  }
}