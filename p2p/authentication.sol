pragma solidity ^0.8.0;

contract P2PAuthentication {
    address[] public peers;
    mapping(address => bool) public peerAuthenticated;

    event PeerAuthenticated(address peer);

    function authenticatePeer(address peer) public {
        require(
            msg.sender == peer,
            "Only the peer can authenticate themselves."
        );
        peers.push(peer);
        peerAuthenticated[peer] = true;
        emit PeerAuthenticated(peer);
    }

    function isPeerAuthenticated(address peer) public view returns (bool) {
        return peerAuthenticated[peer];
    }
}

//p2p usd/inr etc test 1.0
