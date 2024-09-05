async function click(){
    setTimeout(() => {
        console.log(obj);
    }, 2000);
}

async function play(){
    for (let id = 0; id < 1000; id++) {
    await click();
}
}