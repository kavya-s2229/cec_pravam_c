var db = firebase.firestore();

firebase.auth().onAuthStateChanged((user) => {
  if (user) {
    db.collection("tasks")
      .where("userId", "==", user.uid)
      .onSnapshot((snapshot) => {
        let tasks = snapshot.docs.map((doc) => ({ id: doc.id, ...doc.data() }));
        renderTasks(tasks);
      });
  }
});
