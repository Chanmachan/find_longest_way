# find_longest_way
このプロジェクトは標準入力から渡されたファイルを解析し、最長距離を通るルートを探索します。

### 環境構築
プロジェクト内でboostライブラリを使うため、エラーが出る場合には簡易的なdocker環境でビルドしてください。
```bash
# プロジェクトルート
docker build . -t <tag_name>
docker run -it -v $(pwd):/app -w /app <tag_name> bash
```

### コンパイルと実行
```bash
make
# find_longest_wayというファイルが作成される
./find_longest_way <データファイル>
# dataディレクトリのサンプルファイルもしくは作成したファイルを指定
```

### テストデータの生成
テストデータは下記のコマンドで作成できます
```bash
python3 custom_input_script.py 80 160 10.0
# 80->node数, 160->edgeの数, 10.0->重み(距離)の最大値
```

### その他
#### デバッグモード
最長経路の合計距離と出力し、output.dotというファイルが作成されます。
```bash
make debug
```
そのdotファイルからpngファイルを作成します。だいたいのグラフの結びつきを確認できます。
※描画される距離は全く正確ではありません。
```bash
dot -Tpng output.dot -o output.png
```
### テスト
単体テストを半自動で行います。基本的な入力に対するチェックを行っています。
```bash
make test
```
