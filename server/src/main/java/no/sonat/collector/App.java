package no.sonat.collector;

import io.dropwizard.Application;
import io.dropwizard.setup.Bootstrap;
import io.dropwizard.setup.Environment;
import no.sonat.collector.influx.InfluxBundle;

/**
 * @author zapodot
 */
public class App extends Application<CollectorConfiguration> {

    @Override
    public void run(final CollectorConfiguration collectorConfiguration, final Environment environment) throws Exception {

    }

    @Override
    public void initialize(final Bootstrap<CollectorConfiguration> bootstrap) {
        bootstrap.addBundle(new InfluxBundle());
    }

    public static void main(String[] args) {
        try {
            new App().run(args);
        } catch (Exception e) {
            System.err.println("Kunne ikke starte");
            e.printStackTrace(System.err);
        }
    }
}
