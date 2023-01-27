pragma solidity ^0.8.0;

contract MerkelTree {
    bytes32[] public leaves;
    mapping(bytes32 => bytes32) public tree;

    function addLeaf(bytes32 leaf) public {
        leaves.push(leaf);
        bytes32 leafIndex = bytes32(uint(leaves.length) - 1);
        tree[leafIndex] = leaf;
        bytes32 parentIndex = leafIndex / 2;
        while (parentIndex > 0) {
            tree[parentIndex] = keccak256(
                tree[2 * parentIndex] + tree[2 * parentIndex + 1]
            );
            parentIndex /= 2;
        }
    }

    function getRoot() public view returns (bytes32) {
        return tree[1];
    }

    function verify(
        bytes32 root,
        bytes32 leaf,
        uint leafIndex
    ) public view returns (bool) {
        bytes32 currentHash = leaf;
        while (leafIndex > 1) {
            if (leafIndex % 2 == 0) {
                currentHash = keccak256(currentHash + tree[leafIndex + 1]);
            } else {
                currentHash = keccak256(tree[leafIndex - 1] + currentHash);
            }
            leafIndex /= 2;
        }
        return currentHash == root;
    }
}

//gas fee high gewi > 1
