class Skiplist {
    class Node {
        int val;
        Node next, down;
        public Node(int val, Node next, Node down) {
            this.val = val;
            this.next = next;
            this.down = down;
        }
    }

    private Node head = new Node(-1, null, null);
    private Random rand = new Random();

    public Skiplist() {}

    public boolean search(int target) {
        Node curr = head;
        while (curr != null) {
            // Move right as long as the next value is smaller than target
            while (curr.next != null && curr.next.val < target) {
                curr = curr.next;
            }
            if (curr.next != null && curr.next.val == target) return true;
            // Move down to the next level
            curr = curr.down;
        }
        return false;
    }

    public void add(int num) {
        Deque<Node> stack = new ArrayDeque<>();
        Node curr = head;
        
        // 1. Find the insertion points at every level
        while (curr != null) {
            while (curr.next != null && curr.next.val < num) {
                curr = curr.next;
            }
            stack.push(curr);
            curr = curr.down;
        }

        // 2. Insert at the bottom level and potentially promote upwards
        boolean insertUp = true;
        Node downNode = null;
        while (insertUp && !stack.isEmpty()) {
            Node prev = stack.pop();
            prev.next = new Node(num, prev.next, downNode);
            downNode = prev.next;
            // 50% chance to go up one level
            insertUp = rand.nextBoolean();
        }

        // 3. If we promoted all the way up, create a new top level
        if (insertUp) {
            head = new Node(-1, null, head);
        }
    }

    public boolean erase(int num) {
        Node curr = head;
        boolean found = false;
        while (curr != null) {
            while (curr.next != null && curr.next.val < num) {
                curr = curr.next;
            }
            if (curr.next != null && curr.next.val == num) {
                found = true;
                curr.next = curr.next.next; // Delete the node at this level
            }
            curr = curr.down; // Move down to delete from lower levels
        }
        return found;
    }
}